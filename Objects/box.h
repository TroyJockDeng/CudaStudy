#ifndef BOX_H
#define BOX_H

/**
 * Box Object
 * Taken in length, width, height
 * Ouput the volume
 * */
struct box
{
    /* data */
    public:
        int length;
        int width;
        int height;

    int volume(int length, int width, int height){
        return length * width * height;
    }
};


#endif