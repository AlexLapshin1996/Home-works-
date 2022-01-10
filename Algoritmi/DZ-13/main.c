#include "geek.h"
#include "stdbool.h"

typedef struct Queue
{
    int*data;
    int pointer;
    int size;
}Queue;

Queue *data_queue(int size)
{
    Queue * queue = (Queue*) malloc(sizeof (Queue));
    queue->pointer=-1;
    queue->size=size;
    queue->data=(int*) malloc(sizeof (int));
    for (int i = 0; i < size; i++)
    {
     queue->data[i]=0;
    }
    return queue;
}
void enqueue(Queue*queue,int data)
{
    if(queue->pointer < queue->size-1)
    {
        queue->pointer++;
        queue->data[queue->pointer]=data;
    }
    else
    {
        fprintf(stderr,"Queue oveflow\n");
    }

}
int dequeue(Queue*queue)
{
    if(queue->pointer>0)
    {
        fprintf(stderr,"Queue is empty\n");
        return -1;
    }
    int value = queue->data[0];
    queue->pointer--;
    for (int i = 0; i <= queue->pointer; i++)
    {
     queue->data[i] = queue->data[i+1];
        return value;
    }
}
void free_queue(Queue*queue)
{
    free(queue->data);
    free_queue(queue);
}

typedef struct Node
{
    struct Node*next;
    int data;
}Node;

typedef struct SL_list
{
    Node*head;
    unsigned int size;
}SL_list;

void init_list(SL_list*list)
{
    list->head=NULL;
    list->size=0;
}

int push(SL_list*stack,int data)
{
    Node*node=(Node*) malloc(sizeof (Node));
    if(node==NULL)
    {
        fprintf(stderr,"Stack overflow\n");
        return 0;
    }

    node->data=data;
    node->next=stack->head;
    stack->head=node;
    stack->size++;
    return 1;
}

int pop(SL_list*list)
{
    int data;
    Node *temp;
    if(list->size==0)
    {
        return -1;
    }
    data = list->head->data;
    temp=list->head;
    list->size--;
    if(list->size==0)
    {
        list->head=NULL;
    }
    else
    {
        list->head=list->head->next;
    }
    free(temp);

    return data;
}

void free_list(SL_list*list)
{
    Node *temp;
    while(list->head>0)
    {
        temp=list->head;
        list->size--;
        if(list->size>0)
        {
            list->head=list->head->next;
        }
        free(temp);
    }
    free(list);
}

typedef struct Matrix_x
{
    int M;
    int **matrix;
}Matrix_x;

typedef struct NodeLinks
{
    int node;
    int links;
}NodeLinks;

Matrix_x * x_matrix(const int M)
{
    Matrix_x * x_matrix_x = (Matrix_x*) malloc(sizeof (Matrix_x));
    x_matrix_x->M=M;
    x_matrix_x->matrix=(int**) malloc(M*sizeof (int*));
    for (int i = 0; i < M; i++)
    {
        x_matrix_x->matrix[i]=(int*) malloc(M*sizeof (int));
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
         x_matrix_x->matrix[i][j]=0;
        }
    }
    return x_matrix_x;
}

void print_x_matrix(Matrix_x*matrix)
{
    for (int i = 0; i < matrix->M; i++)
    {
        for (int j = 0; j < matrix->M; j++)
        {
            printf("%3d",matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

int unvisited_node(Matrix_x*graph,int current_node,int * visited_nodes)
{
    for (int i = 0; i < graph->M; i++)
    {
    if(graph->matrix[current_node][i]==1 && visited_nodes[i]==0)
    {
        return i;
    }

    }
    return -1;
}

void graph_depth_traversal(Matrix_x*graph)
{
    int next_node;
    int *visited_nodes = (int*) malloc(graph->M*sizeof (int));
    SL_list *stack = (SL_list*) malloc(sizeof (SL_list));
    init_list(stack);

    visited_nodes[0]=1;
    printf("%3d",0);
    push(stack,0);

    while (stack->size>0)
    {
        next_node= unvisited_node(graph,stack->head->data,visited_nodes);
        if(next_node==-1)
        {
            pop(stack);
        }
        else
        {
            visited_nodes[next_node]=1;
            printf("%3d",next_node);
            push(stack,next_node);
        }
    }
    printf("\n");
    free_list(stack);
    free(visited_nodes);
}

NodeLinks **links_count(const int M)
{
    NodeLinks **node_links = (NodeLinks**) malloc(M*sizeof (NodeLinks));
    for (int i = 0; i < M; i++)
    {
        node_links[i]=(NodeLinks*) malloc(sizeof (NodeLinks));
    }
    for (int i = 0; i < M; i++)
    {
    node_links[i]->links=0;
    node_links[i]->node=i;
    }
    return node_links;
}

void count_links_recursive(Matrix_x*graph,int node,NodeLinks**links)
{
    if(node>=graph->M)
    {
        return;
    }
    for (int i = 0; i < graph->M; i++)
    {
     if(node!=i && graph->matrix[node][i]==1)
     {
         links[node]->links++;
     }
    }
    count_links_recursive(graph,node+1,links);

}

void sort_links_count(NodeLinks**links,const int size)
{
    NodeLinks *value;

    for (int i = 0; i < size; i++)
    {
     value=links[i];

        for (int j = i; j > 0 && links[j-1]->links < value->links; j--)
        {
            links[j]=links[j-1];
            links[j]=value;
        }
    }
}

void print_links_count(NodeLinks** links,const int size)
{
    printf("node(links): ");
    for (int i = 0; i < size; i++)
    {
        printf("%d(%d) ",links[i]->node,links[i]->links);
        printf("\n");
    }
}

void free_links_count(NodeLinks**links,const int size)
{
    for (int i = 0; i < size; i++)
    {
        free(links[i]);
        free(links);
    }
}

void count_links_queue(Matrix_x*graph,int node,NodeLinks**links)
{
    Queue *queue= data_queue(graph->M);
    int*visited_nodes = (int*) malloc(graph->M*sizeof (int));

    enqueue(queue,node);
    while(queue->pointer>=0)
    {
        int ind = dequeue(queue);
        if(visited_nodes[ind]==1)
        {
            continue;
        }
        visited_nodes[ind]=1;
        for (int i = 0; i < graph->M; i++)
        {
         if(graph->matrix[ind][i]==1)
         {
             if(i!=ind)
             {
                 links[ind]->links++;
             }
             if(visited_nodes[i]==0)
             {
                 enqueue(queue,i);
             }
         }
        }

    }
    free(visited_nodes);
    free_queue(queue);
}

int main()
{
   const int M = 9;

   Matrix_x *graph = x_matrix(M);
   if(graph==NULL)
   {
       return 1;
   }

    graph->matrix[0][1] = 1;
    graph->matrix[0][2] = 1;
    graph->matrix[1][0] = 1;
    graph->matrix[1][3] = 1;
    graph->matrix[1][6] = 1;
    graph->matrix[2][0] = 1;
    graph->matrix[2][2] = 1;
    graph->matrix[2][7] = 1;
    graph->matrix[3][1] = 1;
    graph->matrix[3][4] = 1;
    graph->matrix[3][5] = 1;
    graph->matrix[4][3] = 1;
    graph->matrix[5][3] = 1;
    graph->matrix[6][1] = 1;
    graph->matrix[6][6] = 1;
    graph->matrix[7][2] = 1;
    graph->matrix[7][8] = 1;
    graph->matrix[8][7] = 1;
    graph->matrix[8][8] = 1;

    print_x_matrix(graph);
    printf("The depht-first traversal of the graph with using stack\n");
    graph_depth_traversal(graph);

    NodeLinks **links = links_count(M);
    count_links_recursive(graph,0,links);
    sort_links_count(links,M);
    printf("Recursive graph nodes links count:\n");
    print_links_count(links,M);
    free_links_count(links,M);

    printf("\n");

    NodeLinks **links_q = links_count(M);
    count_links_queue(graph,0, links_q);
    sort_links_count(links_q,M);
    printf("Graph nodes links count\n");
    print_links_count(links_q,M);
    free_links_count(links_q,M);




    return 0;
}
