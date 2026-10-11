package com.plantHandler.wateringSystem;

import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@CrossOrigin(origins = "http://localhost:5173")
@RestController
public class ESP32Controller {
    private ESP32Handler handler;

    public ESP32Controller(ESP32Handler handler) {
        this.handler = handler;
    }

    @GetMapping ("/measure")
    public String proxyMeasure() {
        return handler.measure();
    }

    @GetMapping ("/water")
    public String proxyWater() {
        return handler.water();
    }
}
