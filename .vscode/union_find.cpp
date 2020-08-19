// 并查集模板
class UnionFind {
    public:
        // 存储每个元素的父节点
        vector<int> parent;
        // 存储id与名字之间的对应关系
        vector<string> names;
        // 存储每个名字的频率
        vector<int> ranks;
        // 初始化
        // length 为节点数
        UnionFind(vector<string>& _names, vector<int>& _ranks, int length = 0) {
            parent.resize(length);
            // 初始状态下, 所有元素的父节点都是其本身
            // 其中i 表示该节点编号
            for (int i = 0; i < length; i++) {
                parent[i] = i;
            }
            names = _names;
            ranks = _ranks;
        }

        // 查询操作
        int find(int index) {
            // 完全压缩 -- 非递归版本(因为递归写法很容易因为递归深度问题爆栈)
            int root = index;
            while (root != parent[root]) {
                root = parent[root];
            }
            // 然后从节点index到节点root的这条路径的所有节点都设置其parent为root, 直接指向根节点
            while (index != root) {
                int temp = parent[index];
                parent[index] = root;
                index = temp;
            }
            return root;
        }

        void merge(int index1, int index2) {
            int parent1 = find(index1), parent2 = find(index2);
            // 判断 index1 与 index2 是否在一个并查集内
            if (parent1 == parent2) {
                return;
            }
            // 注意：这里比较的都是并查集中集合的代表元 parent1 / parent2, 而不是节点 index1 / index2
            // 注意: 选择字典序最小的名字作为真实名字(也就是所谓的并查集的代表元))
            if(names[parent1] <= names[parent2]){
                parent[parent2] = parent1;
                ranks[parent1] += ranks[parent2];
            }else{
                parent[parent1] = parent2;
                ranks[parent2] += ranks[parent1];
            }
            return;
        }
        
        // 判断两个元素是否属于同一个集合
        bool connected(int index1, int index2) {
            int parent1 = find(index1), parent2 = find(index2);
            // 判断 index1 与 index2 是否在一个并查集内
            if (parent1 == parent2) {
                return true;
            }
            return false;
        }
};
class Solution {
public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        // 名字的等价性具有传递性、自反性、对称性
        // 因此这种关系是一种动态连通性
        // 所以可以初步猜想用并查集来解决
        // 对于连通性问题首先考虑使用并查集
        // 其实也可以看做是一个无向图中的连通集个数问题(可以使用DFS/BFS)
        int len = names.size();
        if(len == 0){
            return {};
        }
        vector<string> _names;
        unordered_map<string, int> tag;
        vector<int> ranks;
        for(int i = 0; i < len; i++){
            string str = names[i];
            int index = str.find('(');
            string name = str.substr(0, index);
            tag[name] = i;
            _names.push_back(name);
            string nums = str.substr(index + 1, str.size() - index - 2);
            // 将string对象转换为数字
            int x;
        　　stringstream ss(nums);
        　　ss>>x;
            ranks.push_back(x);
        }
        UnionFind datas = UnionFind(_names, ranks, len);
        for(int i = 0; i < synonyms.size(); i++){
            string str = synonyms[i];
            int index1 = str.find('(');
            int index2 = str.find(',');
            int index3 = str.find(')');
            string name1 = str.substr(index1 + 1, index2 - index1 - 1);
            string name2 = str.substr(index2 + 1, index3 - index2 - 1);
            datas.merge(tag[name1], tag[name2]);
        }
        vector<string> res;
        for(int i = 0; i < len; i++){
            if(datas.parent[i] == i){
                string str = datas.names[i];
                str +="(";
                // 将数字转换为string对象
                // 常见的一些字符串与数字的转换方式: https://www.cnblogs.com/St-Lovaer/p/11398993.html
                int nums = datas.ranks[i];
                stringstream ss;
                ss << nums;
                string temp =ss.str();
                // clear才能使答案正确
                ss.clear();
                str += temp;
                str +=")";
                res.push_back(str);
            }
        }
        return res;
    }
};
