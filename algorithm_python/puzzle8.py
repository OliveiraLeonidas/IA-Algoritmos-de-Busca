# Estado inicial
initial_state = [
  ["7", "1", "#"],
  ["5", "6", "4"],
  ["3", "8", "2"],
]

# Estado objetivo
obj_state = [
  ["1", "2", "3"],
  ["4", "5", "6"],
  ["7", "8", "#"],
]
# state = [
#   ["1", "2", "8"],
#   ["4", "5", "3"],
#   ["7", "#", "6"],
# ]

# Restrições


#movimentos validos
# se a pos de # for igual (1, 1), existem 4movimentos possíveis
# se estiver em uma das pontas, por exemplo (0, 0), (0, 2), (2, 0), (2, 2)
# existem dois movimentos possíveis
