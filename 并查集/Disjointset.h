#include <vector>
using std::vector;

struct Node
{
    int father; // 父节点
    int rank;   // 秩，表示每个节点所在树的高度
    int size;   // 节点所在集合的大小

    Node()
    {}
    Node(int id) : father(id), rank(1), size(1) 
    {}
};

struct DisjointSet
{
    vector<Node> nodes;

    DisjointSet(int n) : nodes(n)
    {
        for (int i = 0; i < n; ++i)
        {
            nodes[i] = Node(i);
        }
    }

    int FindSet(int x)
    {   // 进行路径压缩处理，后续查找更快，但会破坏树的结构，某些情况下不能使用，删除对 fathers[x] 的赋值即可
        return nodes[x].father == x ? x : nodes[x].father = FindSet(nodes[x].father);
    }

    void Merge(int x, int y)
    {   // 按秩进行启发式合并，将秩较小的集合合并到秩较大的集合上，使得树的高度尽可能小
        int set_x = FindSet(x);
        int set_y = FindSet(y);
        if (nodes[set_x].rank < nodes[set_y].rank)
        {
            nodes[set_x].father = set_y;
            nodes[set_y].size += nodes[set_x].size;
        }
        else
        {
            nodes[set_y].father = set_x;
            nodes[set_x].size += nodes[set_y].size;
            if (nodes[set_x].rank == nodes[set_y].rank)
                nodes[set_x].rank++;
        }
    }

    bool IsSameSet(int x, int y)
    {
        return FindSet(x) == FindSet(y);
    }

    int Size(int x)
    {
        return nodes[FindSet(x)].size;
    }

    void Clear()
    {
        for (int i = 0; i < nodes.size(); ++i)
        {
            nodes[i] = Node(i);
        }
    }
};