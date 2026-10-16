# Set Structure

The set structure is shared by sets, multisets, and fuzzy sets.

```pseudo
type Set {
  vec<u32> contents;
}
```

# Set Operations

```pseudo
func complement(A)
  let result be an empty list
  for element in A
    add !element to result
  end
end
```

```pseudo
func union(A, B)
  let result be an empty list
  for a, b in zip(A, B)
    add a & b to result
  end
end
```

```pseudo
func intersection(A, B)
  let result be an empty list
  for a, b in zip(A, B)
    add a | b to result
  end
end
```

```pseudo
func difference(A, B)
  let result be an empty list
  for a, b in zip(A, B)
    add a & !b to result
  end
end
```

```pseudo
func symmetric_difference(A, B)
  let result be an empty list
  for a, b in zip(A, B)
    add a ^ b to result
  end
end
```

# Multiset Operations

```pseudo
func union(A, B)
  let result be an empty list
  for a, b in zip(A, B)
    add max(a, b) to result
  end
end
```

```pseudo
func intersection(A, B)
  let result be an empty list
  for a, b in zip(A, B)
    add min(a, b) to result
  end
end
```

```pseudo
func difference(A, B)
  let result be an empty list
  for a, b in zip(A, B)
    add max(0, a - b) to result
  end
end
```

```pseudo
func sum(A, B)
  let result be an empty list
  for a, b in zip(A, B)
    add a + b to result
  end
end
```