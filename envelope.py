#!/usr/bin/env pypy3
# -*- coding: utf-8 -*-
# filename: meta_envelope_system_termux.py
import hashlib
import networkx as nx
from typing import List, Optional

# ===============================
# Kategorie-Ebene: Envelope + Morphisms
# ===============================
class Envelope:
    def __init__(self, id: str, payload: str):
        self.id = id
        self.payload = payload
        self.hash = self.compute_hash()
        self.history: List[str] = [self.hash]

    def compute_hash(self) -> str:
        return hashlib.sha256(self.payload.encode('utf-8')).hexdigest()

    def sign(self):
        self.payload += "-signed"
        self.update_hash()

    def encrypt(self):
        self.payload = self.payload[::-1]
        self.update_hash()

    def transform(self, modifier: str):
        self.payload += modifier
        self.update_hash()

    def update_hash(self):
        self.hash = self.compute_hash()
        self.history.append(self.hash)

# ===============================
# Topologie-Ebene: ProcessingNodes
# ===============================
class ProcessingNode:
    def __init__(self, operation_type: str):
        self.operation_type = operation_type
        self.input: List[Envelope] = []
        self.output: Optional[Envelope] = None

    def add_input(self, env: Envelope):
        self.input.append(env)

    def process(self):
        combined_payload = "+".join(env.payload for env in self.input)
        combined_payload = f"[{self.operation_type}]{combined_payload}"
        self.output = Envelope(id=f"proc_{id(self)}", payload=combined_payload)
        return self.output

# ===============================
# Netzwerk-Ebene: Nodes (Empfänger)
# ===============================
class Node:
    def __init__(self, node_id: str, role: str):
        self.node_id = node_id
        self.role = role
        self.inbox: List[Envelope] = []

    def send(self, env: Envelope, targets: List['Node']):
        for target in targets:
            target.receive(env)

    def receive(self, env: Envelope):
        self.inbox.append(env)

    def forward(self, env: Envelope, targets: List['Node']):
        self.send(env, targets)

# ===============================
# Build Meta-System
# ===============================
def build_meta_system():
    envelopes = [Envelope(f"E{i+1}", f"Message_{i+1}") for i in range(10)]
    processing_nodes = [ProcessingNode(f"Op{i+1}") for i in range(5)]

    for i, node in enumerate(processing_nodes):
        in_envs = envelopes[i*2:i*2+2]
        for env in in_envs:
            node.add_input(env)
        out_env = node.process()
        envelopes.append(out_env)

    nodes = [Node(f"N{i+1}", "peer") for i in range(6)]
    nodes[0].send(envelopes[0], [nodes[1], nodes[2]])
    nodes[1].send(envelopes[2], [nodes[3]])
    nodes[2].send(envelopes[4], [nodes[4]])
    nodes[3].forward(envelopes[6], [nodes[5]])
    nodes[4].forward(envelopes[7], [nodes[5]])

    # Netzwerk DAG
    G = nx.DiGraph()
    for env in envelopes:
        G.add_node(env.id, payload=env.payload)
    G.add_edge("E1", "E3")
    G.add_edge("E2", "E3")
    G.add_edge("E3", "E7")
    G.add_edge("E5", "E8")

    return envelopes, processing_nodes, nodes, G

# ===============================
# ASCII DAG Zeichnen
# ===============================
def print_ascii_dag(G: nx.DiGraph):
    print("\n=== ASCII Netzwerk DAG ===")
    for node in G.nodes():
        edges = list(G.successors(node))
        if edges:
            print(f"{node} -> {', '.join(edges)}")
        else:
            print(f"{node} -> []")

# ===============================
# Demo
# ===============================
if __name__ == "__main__":
    envelopes, processing_nodes, nodes, G = build_meta_system()

    print("=== Envelopes ===")
    for e in envelopes:
        print(f"{e.id}: {e.payload} | hash={e.hash}")

    print("\n=== Nodes Inbox ===")
    for n in nodes:
        inbox_ids = [env.id for env in n.inbox]
        print(f"{n.node_id} ({n.role}): {inbox_ids}")

    print_ascii_dag(G)
