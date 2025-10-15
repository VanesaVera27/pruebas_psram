#include "esp_system.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println();
  Serial.println("🔎 Verificando PSRAM en ESP32-CAM...");

  if (psramFound()) {
    Serial.println("✅ PSRAM detectada!");

    // Obtener tamaño en bytes y convertir a MB
    size_t psramSize = ESP.getPsramSize();
    Serial.print("Tamaño de PSRAM: ");
    Serial.print(psramSize / (1024 * 1024));
    Serial.println(" MB");
  } else {
    Serial.println("❌ No se detectó PSRAM.");
  }

  // También se puede imprimir información del heap PSRAM:
  Serial.println();
  Serial.println("📊 Información adicional:");
  Serial.print("Memoria PSRAM libre: ");
  Serial.println(ESP.getFreePsram());
}

void loop() {
  // No hace falta hacer nada en loop
}
