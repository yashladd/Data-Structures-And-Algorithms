
class DisjointSet(object):
    def __init__(self, n) -> None:
        self.rank = [0] * (n+1)
        self.parent = []
        for i in range(n+1):
            self.parent.append(i)
        self.size = [1] * (n + 1)

    def findUParent(self, node):
        if node == self.parent[node]:
            return node
        self.parent[node] = self.findUParent(self.parent[node])
        return self.parent[node]

    def unionByRank(self, u, v):
        ultp_u = self.findUParent(u)
        ultp_v = self.findUParent(v)
        if ultp_u == ultp_v:
            return

        if self.rank[ultp_u] < self.rank[ultp_v]:
            self.parent[ultp_u] = ultp_v 
        elif self.rank[ultp_v] < self.rank[ultp_u]:
            self.parent[ultp_v] = ultp_u
        # Equal ranks
        else: 
            self.parent[ultp_u] = ultp_v
            self.rank[ultp_u] += 1

    def unionBySize(self, u, v):
        ultp_u = self.findUParent(u)
        ultp_v = self.findUParent(v)
        if ultp_u == ultp_v:
            return

        if self.size[ultp_u] < self.size[ultp_v]:
            self.parent[ultp_u] = ultp_v
            self.size[ultp_v] += self.size[ultp_u]
        else:
            self.parent[ultp_v] = ultp_u
            self.size[ultp_u] += self.size[ultp_v]


if __name__ == "__main__":
    ds = DisjointSet(7)
    ds.unionBySize(1,2)
    ds.unionBySize(2,3)
    ds.unionBySize(4,5)
    ds.unionBySize(6,7)
    ds.unionBySize(5,6)
    # check 3 & 7 belong to same component or not
    if ds.findUParent(3) == ds.findUParent(7):
        print("same")
    else:
        print("not same")
    ds.unionBySize(3,7)
     # check 3 & 7 belong to same component or not
    if ds.findUParent(3) == ds.findUParent(7):
        print("same")
    else:
        print("not same")