# 1038

id, quantidade = map(int, input().split())

itens = {
    1: 4.0, 
    2: 4.5,
    3: 5.0,  
    4: 2.0, 
    5: 1.5, 
}

print(f"Total: R$ {quantidade*itens.get(id, 0.0):.2f}")
