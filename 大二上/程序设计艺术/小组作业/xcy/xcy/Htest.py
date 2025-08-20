import random

def generate_test_case(n, m):
    print(f"{n} {m}")
    edges = set()
    for _ in range(m):
        while True:
            u = random.randint(1, n-1)
            v = random.randint(u+1, n)
            if (u, v) not in edges:
                edges.add((u, v))
                cap = random.randint(1, 100000000)
                print(f"{u} {v} {cap}")
                break

print("Small scale test case:")
generate_test_case(10, 15)

print("\nLarge scale test case:")
generate_test_case(9999, 50000)