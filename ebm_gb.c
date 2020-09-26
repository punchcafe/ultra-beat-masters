#include <gb/gb.h>
#include<stdio.h>
#include <gb/font.h>
#include <gb/console.h>
#include <gb/drawing.h>

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
    unsigned int next_beat_index;
    unsigned int is_finished;
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
    int lol;
    lol = 1;
    load_beat(beat, song1[index][0], song1[index][1], song1[index][2]);
}

/*
 * Loads next beat, returns 1 if successful, 0 is no more beats
 * */
void load_next_beat(struct BeatManager* beat_manager, struct Beat *beat){
    if(beat_manager->next_beat_index >= BEATS){
      beat_manager->is_finished=1;
      return;
    }
    load_beat_by_index(beat, beat_manager->next_beat_index);
    beat_manager->next_beat_index++;
}

void burn_down_beat_delay(struct Beat * beat){
    // If the while condition is > 1 this will fail
    while(beat->delay > 2){
            delay(1000UL);
            printf("delay loop!\n");
            printf("Beat: delay, %u duration, %u\n", beat->delay, beat->duration);
            if(beat->delay > 5){
                beat->delay = 0x08u;
                printf("first block\n");
                printf("check it %u\n", beat->delay);
                beat->delay = beat->delay - 0x04u;
            } else {
                printf("else block\n");
                beat->delay = 0x01u;
            }
            printf("out of if: %u\n", beat->delay);
            /**
             * Something seems to reset beat.delay
             */
    }
}

void burn_down_beat_duration(struct Beat * beat){
    while(beat->duration > 1u){
        printf("Beat: delay, %u duration, %u\n", beat->delay, beat->duration);
        beat->duration--;
    }
}

void main(void){
    
    font_t ibm_font, italic_font, min_font;

    /* First, init the font system */
    font_init();

    /* Load all the fonts that we can */
    ibm_font = font_load(font_ibm);  /* 96 tiles */
    italic_font = font_load(font_italic);   /* 93 tiles */
    
    /* Load this one with dk grey background and white foreground */
    color(WHITE, DKGREY, SOLID);
    
    line(0x04,0x04, 0x40, 0x04);
    delay(100Lu);

    min_font = font_load(font_min);

    /* Turn scrolling off (why not?) */
    mode(get_mode() | M_NO_SCROLL);

    /* Print some text! */
    
    /* IBM font */
    font_set(ibm_font);
    printf("Font demo.\n\n");

    beat_manager.next_beat_index = 0;
    beat_manager.is_finished = 0;
    load_next_beat(&beat_manager, &beat);
    while(!beat_manager.is_finished){
        printf("Beat: delay, %u duration, %u\n", beat.delay, beat.duration);
        printf("*******%u\n", beat.delay < 0u); // this is true
        // comparisons seem to break at 0 with unsigned ints
        // ANY VAR Declaration here creates error
        // SOMETHING HERE RESETS DELAY
        
        burn_down_beat_delay(&beat);
        printf("****!!!!****");
        burn_down_beat_duration(&beat);
        printf("*******");
        load_next_beat(&beat_manager, &beat);
    }
    
}