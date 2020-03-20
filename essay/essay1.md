# 如何使用初始化列表消除冗余C++代码

我们在写对map，vector等等容器进行赋值操作的时候，往往会写很多冗余的代码

如下这个情形，就是我们需要对`map<int, Node> node_map` 这样的容器进行初始化， 而且map里面还有结构体。 

然后就开始一边又一遍重复写着相同的代码进行初始化，这样的代码不仅重复而且极易出错

如下所示：

```
struct Node {
    int a;
    float b;
    string c;
}st;

int main (){

    map<int, Node> node_map;
    Node node;
    node.a = 1;
    node.b = 1.1;
    node.c = "adf";
    node_map[0] = node;

    Node node1;
    node1.a = 2;
    node1.b = 1.1;
    node1.c = "2adf";
    node_map[1] = node1;

    Node node2;
    node2.a = 3;
    node2.b = 3.1;
    node2.c = "3adf";
    node_map[2] = node2;

    Node node3;
    node3.a = 3;
    node3.b = 3.1;
    node3.c = "3adf";
    node_map[3] = node3;

    for (pair<int, Node> node_pair : node_map) {
        cout << node_pair.second.c << endl;
    }
}

```

我们其实可以使用结构体的初始化列表的特性，这这段代码已经精简，代码如下： 

```
struct Node {
    int a;
    float b;
    string c;
}st;

int main (){
    map<int, Node> node_map = {
        {0,{1, 1.1, "adf"}},
        {1,{2, 1.1, "1adf"}},
        {2,{3, 1.1, "2adf"}},
        {3,{3, 1.1, "3adf"}},
    };

    for (pair<int, Node> node_pair : node_map) {
        cout << node_pair.second.c << endl;
    }
}

```
