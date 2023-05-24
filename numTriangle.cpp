#include "iostream"
#include "string.h"
#include "math.h"

int main()
{
    int row;//行
    printf("输入三角形行数：");
    scanf("%d",&row);
    int tridata[row][row]={0};
    int trirecord[row][row]={0};
    int path[row][row]={0};//路径
    printf("输入三角形：\n");
    for(int i=0;i<row;i++)//输入三角形
    {
        for(int j=0;j<i+1;j++)
        {
            scanf("%d",&tridata[i][j]);
        }
    }
    for(int i=0;i<row;i++)//记录原数字三角形
    {
        for(int j=0;j<i+1;j++)
        {
            trirecord[i][j]=tridata[i][j];
        }
    }
    for(int i=row-2;i>=0;i--)//动态规划算法
    {
        for(int j=0;j<i+1;j++)
        {
            if(tridata[i+1][j]>tridata[i+1][j+1])
            {
                tridata[i][j]+=tridata[i+1][j];
                path[i][j]=0;
            }
            else
            {
                tridata[i][j]+=tridata[i+1][j+1];
                path[i][j]=1;
            }
        }
    }
    printf("最大总和：%d",tridata[0][0]);
    printf("\n路径:");
    int rowIndex=0;
    int colIndex=0;
    printf("%d",trirecord[rowIndex][colIndex]);
    while(rowIndex<row-1)
    {
        if(path[rowIndex][colIndex]==0)
        {
            rowIndex++;
            printf("--%d",trirecord[rowIndex][colIndex]);
        }
        else
        {
            if(path[rowIndex][colIndex]==1)
            {
                rowIndex++;
                colIndex++;
                printf("--%d",trirecord[rowIndex][colIndex]);
            }
        }
    }
    return 0;
}