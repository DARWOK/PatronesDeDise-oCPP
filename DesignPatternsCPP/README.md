# Tarea 03 | Patron Observer con Arrays Fijos

Este proyecto implementa el patron **Observer** en C++ usando un array fijo para gestionar suscriptores.

## Como ayuda el Observer a desacoplar
El sujeto (Personaje) no conoce detalles de los sistemas que reaccionan. Solo anuncia eventos (Evento).
Los observadores implementan IObserver y se suscriben con agregarObserver. Esto elimina dependencias directas y evita codigo espagueti.

## Diagrama UML

![Image_Alt](https://github.com/DARWOK/PatronesDeDise-oCPP/blob/c68602157218233eb335729365be5f301e45d3af/DesignPatternsCPP/observer_uml.png)

## Captura de pantalla

![Image_Alt](https://github.com/DARWOK/PatronesDeDise-oCPP/blob/c68602157218233eb335729365be5f301e45d3af/DesignPatternsCPP/Screenshot%202025-08-22%20232727.png)

## Tarea 04 | Event Queue y filtrado de peticiones

### Diferencias Observer vs Event Queue
- **Observer (sincrónico):** notifica *al instante* a múltiples observadores. El emisor y receptor comparten el mismo momento de ejecución.
- **Event Queue (asincrónico):** el emisor solo **encola** eventos; el receptor los procesa **después** (por frame, por sistema), controlando ritmo y acumulación.

### Por qué filtrar duplicados en audio
Varias solicitudes del mismo sonido en un frame saturan el mezclador y generan ruido visual/sonoro. Filtrar deja un único sonido representativo por tipo (HIT, JUMP, etc.), reduciendo costo y caos.

### Captura de pantalla

![Image_Alt](https://github.com/DARWOK/PatronesDeDise-oCPP/blob/8e24010ad38093a7e717dd91502cfc470cf2f9df/DesignPatternsCPP/Screenshot%202025-08-23%20012139.png)
