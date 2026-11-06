package com.plantHandler.wateringSystem;

import org.springframework.scheduling.annotation.Scheduled;

public class WateringSystemServer {
    private ESP32Handler handler;

    public WateringSystemServer(ESP32Handler handler) {
        this.handler = handler;
    }

    @Scheduled(fixedRate = (15 * 60  * 1000))  // measure every 15 minutes
    public void runProcess() {
        handler.measure();
    }
}
