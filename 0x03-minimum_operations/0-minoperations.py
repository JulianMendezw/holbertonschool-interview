#!/usr/bin/python3
import math


def minOperations(n):
    """ Calculates the fewest number of operations needed to result in
        exactly n H characters.
        Args:
            @n: integer
        Return:
            the fewest number of operations needed to result in n H characters
    """
    suma = 0
    if n <= 1:
        return suma
    for i in range(2, int(math.sqrt(n) + 1)):
        while n % i == 0:
            suma += i
            n = n // i
    if n > 1:
        suma += n
    return suma