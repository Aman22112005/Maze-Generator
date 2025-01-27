#include <stdio.h>
#include <stdlib.h>

#define W 18// Width
#define L 20 // Length

char arr[W][L];

int generator(int r, int c,int n, int a);
void move(int*r, int*c, int n, int z);
int left(int r,int c);
int right(int r,int c);
int up(int r,int c);
int down(int r,int c);
void printmaze();
int move_possible(int r,int c)
int can_move(int r, int c, int n)


int main() {



    for(int i=0; i<W; i++) {
        for(int j=0; j<L; j++) {
            arr[i][j]='0';
        }

    }

    arr[1][1]=' ';
    generator(1,1,0);


    arr[1][0]=' ';

    for(int i=W-2; i>0; i--) {
        if (arr[i][L-2]==' ')
            arr[i][L-1]=' ';

        break;
    }

    printmaze();



}



int generator(int r, int c,int n, int a) {

    if (move_possible(r,c)) {

        do {
            n=rand()%4;
        } while(!can_move(r,c,n));


        if (can_move(r,c,n)) {
            a=0;
            move(&r,&c,n,1);
            arr[r][c]=' ';
        }
        if (can_move(r,c,n)) {
            a=1;
            move(&r,&c,n,1);
            arr[r][c]=' ';
        }

        generator(r, c, n, a);

    }

    if (r==1 && c==1) {
        return 1;
    }


    move(&r,&c,n,0);
    if (move_possible(r,c))
        generator(r,c,n,a);

    if (a=1)
    {
        move(&r,&c,n,0);
        if (move_possible(r,c))
            generator(r,c,n,a);
    }


}





void printmaze() {

    for(int i=0; i<W; i++) {
        for(int j=0; j<L; j++) {

            printf("%c ",arr[i][j]);

        }
        printf("\n");
    }
    printf("\n\n\n");
}


int left(int r,int c) {

    if(c==1) return 0;

    if(arr[r][c-1]=='0' && arr[r][c-2]=='0' && arr[r-1][c-1]=='0' && arr[r-1][c-2]=='0' && arr[r+1][c-1]=='0' && arr[r+1][c-2]=='0')
        return 1;

    return 0;
}

int right(int r, int c) {

    if(c==L-2) return 0;

    if(arr[r][c+1]=='0' && arr[r][c+2]=='0' && arr[r-1][c+1]=='0' && arr[r-1][c+2]=='0' && arr[r+1][c+1]=='0' && arr[r+1][c+2]=='0')
        return 1;

    return 0;
}

int up(int r, int c) {

    if(r==1) return 0;

    if(arr[r-1][c+1]=='0' && arr[r-2][c+1]=='0' && arr[r-1][c]=='0' && arr[r-2][c]=='0' && arr[r-1][c-1]=='0' && arr[r-2][c-1]=='0') {
        return 1;
    }
    return 0;
}

int down(int r, int c) {

    if(r==W-2) return 0;

    if(arr[r+1][c+1]=='0' && arr[r+2][c+1]=='0' && arr[r+1][c]=='0' && arr[r+2][c]=='0' && arr[r+1][c-1]=='0' && arr[r+2][c-1]=='0')
        return 1;

    return 0;
}

int move_possible(int r,int c) {

    if (left(r,c) || right(r,c) || up(r,c)|| down(r,c))
        return 1;


    return 0;
}


int can_move(int r, int c, int n) {

    if (n==1 && left(r,c))
        return 1;

    if (n==2 && up(r,c))
        return 1;

    if (n==3 && right(r,c))
        return 1;

    if (n==0 && down(r,c))
        return 1;

    return 0;
}



void move(int*r, int*c, int n, int z) {

    if(z==0) {

        switch(n) {

        case 1:
            *c+=1;
            break;

        case 2:
            *r+=1;
            break;

        case 3:
            *c-=1;
            break;

        case 0:
            *r-=1;
            break;

        default:
            break;

        }
    }
    else {
        switch(n) {

        case 1:
            *c-=1;
            break;

        case 2:
            *r-=1;
            break;

        case 3:
            *c+=1;
            break;

        case 0:
            *r+=1;
            break;

        default:
            break;

        }
    }
}
