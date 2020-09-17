#include<stdio.h>

#define BEATS 4

#define UP_DIRECTION 1

const int song1[BEATS][3] = {
    {5, 100, UP_DIRECTION},
    {6, 200, UP_DIRECTION},
    {7, 150, UP_DIRECTION},
    {8, 50, UP_DIRECTION}
};

enum beat_move {UP, DOWN, LEFT, RIGHT};

struct Beat 
{
    unsigned int duration;
    unsigned int delay;
    enum beat_move move;
};

struct BeatManager
{
    int next_beat_index;
};

// Singletons

struct BeatManager beat_manager;
struct Beat beat;

void load_beat(struct Beat *beat, int new_duration, int new_delay, int new_move){
    beat->duration = new_duration;
    beat->delay = new_delay;
    beat->move = new_move;
}

void load_beat_by_index(struct Beat *beat, int index){
    load_beat(beat, song1[index][0], song1[index][1], song1[index][2]);
}

/*
 * Loads next beat, returns 1 if successful, 0 is no more beats
 * */
int load_next_beat(){
    if(beat_manager.next_beat_index >= BEATS){
        return 0;
    }
    load_beat_by_index(&beat, beat_manager.next_beat_index);
    beat_manager.next_beat_index++;
    return 1;
}



int main(){
    beat_manager.next_beat_index = 0;
    while(load_next_beat()){
        while(1){
        printf("Beat duration: %d\n", beat.duration);
        printf("Beat delay: %d\n", beat.delay);
        printf("Beat move: %d\n", beat.move);
        while(beat.delay > 0){
            printf("waiting...");
            beat.delay = beat.delay - 5;
            continue;
        }
        printf("Active Beat!");
        while(beat.duration > 0){
            beat.duration--;
            printf("new beat duration: %d\n", beat.duration);
            continue;
        }
        break;
        }
    }
}