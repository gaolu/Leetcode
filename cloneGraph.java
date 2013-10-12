/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     ArrayList<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    HashMap<UndirectedGraphNode, UndirectedGraphNode> map = new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        map.clear();
        return cloneNode(node);
    }
    private UndirectedGraphNode cloneNode(UndirectedGraphNode node){
        if(node == null) return node;
        if(map.containsKey(node)) return map.get(node);
        else{
            UndirectedGraphNode copy = new UndirectedGraphNode(node.label);
            map.put(node, copy);
            for(UndirectedGraphNode n: node.neighbors){
                copy.neighbors.add(cloneNode(n));
            }
            return copy;
        }
    }
}