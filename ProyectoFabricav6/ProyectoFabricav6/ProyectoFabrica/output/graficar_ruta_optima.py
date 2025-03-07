import matplotlib.pyplot as plt
import networkx as nx
import heapq
from matplotlib.patches import FancyArrowPatch

G = nx.DiGraph()

G.add_node('Fabrica')
G.add_node('Carlos')
G.add_edge('Fabrica', 'Carlos', weight=15)
G.add_edge('Carlos', 'Oro', weight=3)
G.add_edge('Carlos', 'Juanito', weight=12.5)
G.add_node('Oro')
G.add_edge('Fabrica', 'Oro', weight=17)
G.add_edge('Oro', 'Carlos', weight=3)
G.add_node('Dana')
G.add_edge('Fabrica', 'Dana', weight=3)
G.add_edge('Dana', 'Oro', weight=2.1)
G.add_node('Juanito')
G.add_edge('Fabrica', 'Juanito', weight=6.4)
G.add_edge('Juanito', 'Carlos', weight=1.6)
G.add_node('Anita')
G.add_edge('Fabrica', 'Anita', weight=3.4)
G.add_edge('Anita', 'Dana', weight=1.6)
def dijkstra(graph, start, target):
    queue = [(0, start, [])]
    visited = set()
    while queue:
        (cost, node, path) = heapq.heappop(queue)
        if node in visited:
            continue
        path = path + [node]
        if node == target:
            return path
        visited.add(node)
        for neighbor, data in graph[node].items():
            heapq.heappush(queue, (cost + data['weight'], neighbor, path))
    return []

ruta_optima = dijkstra(G, 'Fabrica', 'Carlos')
edges = G.edges(data=True)
weights = [edge[2]['weight'] for edge in edges]
colors = ['red' if node == 'Fabrica' else 'skyblue' for node in G.nodes()]
pos = nx.spring_layout(G, weight='weight', scale=10, k=2)
nx.draw(G, pos, with_labels=True, node_size=700, node_color=colors, font_size=10, font_weight='bold')
nx.draw_networkx_edges(G, pos, width=1.0)
nx.draw_networkx_edge_labels(G, pos, edge_labels={(u, v): d['weight'] for u, v, d in edges})
ruta_edges = [(ruta_optima[i], ruta_optima[i+1]) for i in range(len(ruta_optima)-1)]
nx.draw_networkx_edges(G, pos, edgelist=ruta_edges, edge_color='green', style='dashed', width=2.5)
for u, v in ruta_edges:
    arrow = FancyArrowPatch(pos[u], pos[v], arrowstyle='->', color='green', linewidth=2.5, mutation_scale=15)
    plt.gca().add_patch(arrow)
plt.show()
