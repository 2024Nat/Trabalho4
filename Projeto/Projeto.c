#include <stdio.h>
#define led_pin_red 13
#define ponto 200
#define traco 800
#define gap 125
#define intervalo_letra 250
#define intervalo_ciclo 3000

void piscar_led(int duracao) {
    gpio_put(led_pin_red, true);
    sleep_ms(duracao);
    gpio_put(led_pin_red, false);
    sleep_ms(gap);
}

void enviar_sos() {
    for (int i = 0; i < 3; i++) {
        piscar_led(ponto);
    }
    sleep_ms(intervalo_letra);

    for (int i = 0; i < 3; i++) {
        piscar_led(traco);
    }
    sleep_ms(intervalo_letra);

    for (int i = 0; i < 3; i++) {
        piscar_led(ponto);
    }
    sleep_ms(intervalo_ciclo);
}

int main() {
    gpio_init(led_pin_red);
    gpio_set_dir(led_pin_red, GPIO_OUT);

    while (true) {
        enviar_sos();
    }
}




