#include <stdlib.h> 
typedef int ElemType;
#define maxsize 50//数组，栈等最大空间


//！！以下为顺序结构！！
// 顺序表的结构定义
typedef struct
{
    int data[maxsize]; // 存放数组的数组
    int length; // 顺序表的实际长度
}SeqList;   // 顺序表类型名为SeqList


// 单链表的类型定义
typedef struct node
{
    int data; // 数据域
    struct node *next; // 指针域
}Node, *LinkList;

// 双向循环链表结点的类型定义
 typedef struct DNode
{
    int data;
    struct DNode *prior; 
    struct DNode *next;
}DNode, *DLinkList;

// 顺序栈
typedef struct seqstack
{
    int data[maxsize];
    int top;    // 标志栈顶位置的变量
}SeqStk;


// 链栈
typedef struct lnode
{
    int data;
    struct lnode *next;
}LStk;

// 顺序队列
typedef struct seqque
{
    int data[maxsize];
    int front, rear;
}SqQue;
//循环队列,实则与上一样
typedef struct cycque
{
    int data[maxsize];
    int front,rear;
}CyQue;

// 链式队列类型定义
typedef struct LQueueNode
{
    int data;
    struct LQueueNode *next;
}LQueNode;

typedef struct LQueue
{
    LQueNode *front, *rear;
}LQue;

//！！以下为矩阵及广义表！！

//矩阵转置、相加、相乘（较简单）
//三元组（较简单)
//上三角、下三角矩阵 存储到一维数组（较简单）

//稀疏矩阵“十字链表” 的 数据结点 和 头节点
typedef struct sznode
{
    int row,col;//行号和列号
    //最左和最上不存储data，其row和clo设为-1
    struct sznode *right,*down; //指向右边及下方结点指针
    float data;//值域   
}SZNode;
//头结点，左上角那一个
typedef struct   
{
    SZNode *r,*c;//指向两头结点数组
    int m,n,k;//存储整个十字链表 行、列、非空结点总数
}CrossList;






// ！！以下为树结构！！

// 二叉链表的类型定义
typedef struct btnode
{
    int data;//默认int型，按需修改
    struct btnode *lchild, *rchild; // 指向左右孩子的指针
}BTNode, *BinTree;

// 三叉链表的类型定义
typedef struct ttnode
{
    int data;
    struct ttnode *lchild, *parent, *rchild;
}*TBinTree;

//线索二叉树
typedef struct TBTNode
{
    int data;
    int ltag;  //左标识位，为0时，lchild指向左孩子；为1时，指向前驱
    int rtag;  //右标识位，为0时，lchild指向右孩子；为1时，指向后继
    struct TBTNode *lchild;
    struct TBTNode *rchild;    
}TBTNode;

//！！以下为图的基本结构！！

//邻接矩阵（顺序）
typedef struct gp
{
    int vexs[maxsize]; // 顶点data信息
    int edges[maxsize][maxsize]; // 邻接矩阵核心，无权图用int:1表示邻接
                        //有权图换作float记录权值，若无邻接用极大数表示
    int vexnum, edgenum; // 顶点数，边数
}MGraph;


// 邻接表（链式）
// 边结点
typedef struct arcnode
{
    int adjvex; // 通过该边邻接的后继结点编号
    int weight; // 权值
    struct arcnode *nextarc;
}ArcNode;
// 顶点结点
typedef struct vexnode
{
    int vextex; // 顶点编号
    ArcNode *firstarc; // 指向第一条边的指针
}VexNode;
typedef struct agp
{
   VexNode adjlist[maxsize];//邻接表
    int vexnum, arcnum; // 顶点和边数
}AGraph;


//逆邻接表
//任一表头结点下的边结点的数量是图中该结点入度的弧的数量，与邻接表相反。
//图的邻接表，反映的是节点的出度邻接情况；图的逆邻接表反映的是节点的入度邻接情况。