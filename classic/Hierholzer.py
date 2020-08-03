#https://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph/
#Given a directed Eulerian graph, print an Euler circuit.
#Euler circuit is a path that traverses every edge of a graph,
#and the path ends on the starting vertex.

def printCircuit(adj):
    edge_count = {}
    for i in range(len(adj)):
        edge_count[i] = len(adj[i])

    if len(adj) == 0:
        return

    cur_path = [0]
    circuit = []

    while cur_path:
        cur_v = cur_path[-1]
        if adj[cur_v]:
            next_v = adj[cur_v].pop()
            cur_path.append(next_v)
        else:
            circuit.append(cur_path.pop())
        print ("cur_path: ", cur_path)
        print ("circuit", circuit)

    print(circuit)
    for i in range(len(circuit)-1, -1, -1):
        print(circuit[i] , end = " -> ")
    print()
    print()


if __name__=="__main__":
    adj1 = [[]*3 for i in range(3)]
    adj1[0].append(1)
    adj1[1].append(2)
    adj1[2].append(0)
    printCircuit(adj1)

    adj2 = [[]*7 for i in range(7)]
    adj2[0].append(1)
    adj2[0].append(6)
    adj2[1].append(2)
    adj2[2].append(0)
    adj2[2].append(3)
    adj2[3].append(4)
    adj2[4].append(2)
    adj2[4].append(5)
    adj2[5].append(0)
    adj2[6].append(4)
    printCircuit(adj2)

    adj3 = [[]*5 for i in range(5)]
    adj3[0].append(1)
    adj3[1].append(3)
    adj3[1].append(2)
    adj3[2].append(0)
    adj3[3].append(4)
    adj3[4].append(1)
    printCircuit(adj3)
