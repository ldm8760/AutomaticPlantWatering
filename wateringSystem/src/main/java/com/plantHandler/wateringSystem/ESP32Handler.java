package com.plantHandler.wateringSystem;

import org.springframework.stereotype.Service;
import org.springframework.web.client.RestClient;

@Service 
public class ESP32Handler {
    private final RestClient restClient;

    public ESP32Handler(RestClient.Builder restClientBuilder) {
        this.restClient = restClientBuilder.baseUrl("http://plantHandler.local").build();
    }

    public String measure() {
        return this.restClient.get().uri("/measure").retrieve().body(String.class);
    }

    public String water() {
        return this.restClient.get().uri("/water").retrieve().body(String.class);
    }
}
