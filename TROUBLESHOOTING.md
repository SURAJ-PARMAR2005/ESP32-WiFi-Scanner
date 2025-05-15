# 🛠️ Troubleshooting Guide – ESP32 Wi-Fi Scanner Project

This guide lists common issues users might face when running the ESP32 Wi-Fi Scanner project and how to resolve them.

---

## 1. 🔌 ESP32 Not Detected in Arduino IDE

**Issue:** ESP32 board not showing in Tools → Port

**Solution:**
- Make sure you’ve installed the correct USB-to-Serial driver (e.g., CP210x or CH340).
- Check the USB cable – some only support charging, not data.
- Try a different USB port or restart the Arduino IDE.

---

## 2. 📡 No Wi-Fi Networks Detected

**Issue:** Serial Monitor shows "Scanning..." but lists no Wi-Fi networks.

**Possible Fixes:**
- Ensure you’re in an area with active Wi-Fi signals.
- Check if `WiFi.mode(WIFI_STA);` is set correctly in code.
- Make sure the ESP32 antenna isn’t blocked or facing a shielded surface.

---

## 3. 🧾 Serial Monitor Not Showing Output

**Issue:** Nothing is printed in the Serial Monitor.

**Solution:**
- Confirm you selected the correct COM port (Tools → Port).
- Baud rate should be `115200` to match `Serial.begin(115200);`
- Make sure `Serial Monitor` is open and not `Serial Plotter`.

---

## 4. ⚙️ Compilation Issues

**Issue:** Errors during compiling

**Solution:**
- Ensure ESP32 board package is installed (Arduino → Preferences → Board Manager URL: `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`)
- Go to **Tools → Board → ESP32 Dev Module**
- Make sure you selected the correct board model

---

## 5. 🔁 Continuous Reboot / Boot Loop

**Issue:** The board keeps restarting repeatedly.

**Solution:**
- Check if there's any Serial print overload in `loop()`.
- Disconnect peripherals from GPIO 0, 2, 15, etc. that affect boot mode.
- Use a simple sketch like Blink to test basic stability.

---

##
