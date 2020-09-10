class UnionFind {
    vector<int> component;
    int distinctComponents;
public:
    /*
     *   Initially all 'n' nodes are in different components.
     *   e.g. component[2] = 2 i.e. node 2 belong to component 2.
     */
    UnionFind(int n) {
	    distinctComponents = n;
        for (int i=0; i<=n; i++) {
            component.push_back(i);
        }
    }
    
    /*
     *   Returns true when two nodes 'a' and 'b' are initially in different
     *   components. Otherwise returns false.
     */
    bool unite(int a, int b) {       
        if (findComponent(a) == findComponent(b)) {
            return false;
        }
        component[findComponent(a)] = b;
        distinctComponents--;
        return true;
    }
    
    /*
     *   Returns what component does the node 'a' belong to.
     */
    int findComponent(int a) {
        if (component[a] != a) {
            component[a] = findComponent(component[a]);
        }
        return component[a];
    }
    
    /*
     *   Are all nodes united into a single component?
     */
    bool united() {
        return distinctComponents == 1;
    }
};

