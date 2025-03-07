import matplotlib.pyplot as plt
import networkx as nx

G = nx.Graph()

G.add_node('Fabrica')

pos = nx.spring_layout(G, weight='weight')
edges = G.edges(data=True)
weights = [edge[2]['weight'] for edge in edges]
nx.draw(G, pos, with_labels=True, node_size=700, node_color='skyblue', font_size=10, font_weight='bold')
nx.draw_networkx_edge_labels(G, pos, edge_labels={(u, v): d['weight'] for u, v, d in edges})
plt.show()
