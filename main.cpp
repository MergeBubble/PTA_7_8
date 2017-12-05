#include "stdio.h"
int main(){
    int N , M ;
    scanf("%d%d" , &N,&M) ;
    int map[N+1][N+1 ] ;
    int index = 0 ;
    int min = 999 ;
    int pos1 , pos2 , value ;
    int MAX_ = 999999 ;
    for(int i = 0 ; i < N+1 ;i++)   // init_map
        for(int j = 0 ; j < N+1 ; j++)
        {
            if(i==j)
                map[i][j] = 0 ;
            else
                map[i][j] = MAX_ ;
        }

    for(int i = 0 ; i< M ; i++){
        scanf("%d%d%d" , &pos1 , &pos2 , &value);
        map[pos1][pos2] = value ;
        map[pos2][pos1] = value ;
    }


    for(int i = 1 ; i < N+1 ; i++ )
        for(int j = 1 ; j < N+1 ; j++)
            for(int K = 1 ; K< N+1 ; K ++)
            {
                if( (map[j][i] + map[i][K]) < map[j][K] )
                    map[j][K] = map[j][i] + map[i][K] ;
            }
#if 0
    for(int i = 1 ; i < N+1 ; i++) {
        for (int j = 1; j < N + 1; j++)
            printf("%d ", map[i][j]);
        printf("\n") ;
    }
#endif

    for(int i = 1 ; i < N+1 ; i++)
    {
        int max = 0 ;
        for(int j = 1 ; j < N+1 ; j++)
        {
            if(map[i][j] >max ) {
                max = map[i][j];
            }
        }
        if(max < min )
        {
            min = max ;
            index = i  ;
        }
    }
    if(index == 0 )
        printf("0");
    else
        printf("%d %d" , index ,  min ) ;


    return  0  ;
}