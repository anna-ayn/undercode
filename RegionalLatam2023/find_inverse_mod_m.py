def modular_inverse(n, mod):
    return pow(n, mod - 2, mod)


# Example usage
mod = 1000000007
n = 2  # Change this value to find the inverse of different numbers
inverse = modular_inverse(n, mod)
print(inverse)
