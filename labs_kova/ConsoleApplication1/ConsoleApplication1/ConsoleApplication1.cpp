
#include <iostream>
#include <string.h>

class Hui {
    bool head;
    bool stvol;
    bool balls;
    bool erection;
    int amount_of_balls;
    int length;

    Hui() {
        head = true;
        stvol = true;
        balls = true;
        erection = false;
        amount_of_balls = 2;
        length = 7;
    }

    void masturbation();
    void obrezanie();
    void chingishan(int amount);
    int get_balls();
};

int Hui::get_balls() {

}

void Hui::masturbation() {
    erection = true;
    length += 3;
}

void Hui::obrezanie() {
    head = false;
}

void Hui::chingishan(int amount) {
    amount_of_balls = amount;
}


int main()
{
        std::cout << "hui";

}