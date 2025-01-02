# Push Swap

## Project Rules

The program is composed of 2 stacks named `a` and `b`.

To start with:

- `a` contains a random number of either positive or negative numbers without any duplicates.
- `b` is empty.

The goal is to sort in ascending order numbers into stack `a`.

## Operations

- `sa`: swap `a` - Swap the first 2 elements at the top of stack `a`. (Do nothing if there is only one or no elements).
- `sb`: swap `b` - Swap the first 2 elements at the top of stack `b`. (Do nothing if there is only one or no elements).
- `ss`: Perform `sa` and `sb` at the same time.
- `pa`: push `a` - Take the first element at the top of `b` and put it at the top of `a`. (Do nothing if `b` is empty).
- `pb`: push `b` - Take the first element at the top of `a` and put it at the top of `b`. (Do nothing if `a` is empty).
- `ra`: rotate `a` - Shift up all elements of stack `a` by 1. The first element becomes the last one.
- `rb`: rotate `b` - Shift up all elements of stack `b` by 1. The first element becomes the last one.
- `rr`: Perform `ra` and `rb` at the same time.
- `rra`: reverse rotate `a` - Shift down all elements of stack `a` by 1. The last element becomes the first one.
- `rrb`: reverse rotate `b` - Shift down all elements of stack `b` by 1. The last element becomes the first one.
- `rrr`: Perform `rra` and `rrb` at the same time.

## Radix Sort Algorithm

### Algorithm Breakdown

#### Variables Used

- `tmp_stack_a`: A temporary pointer used to traverse `stack_a`.
- `bit`: The current bit position being processed.
- `nb`: Counter for iterating through the elements of `stack_a` during each bit pass.
- `size`: Total number of elements in `stack_a`.
- `max_bits`: The total number of bits required to represent the largest number in `stack_a`.

#### Code snippet

```c
void	radix_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*tmp_stack_a;
	int				bit;
	int				nb;
	int				size;
	int				max_bits;

	bit = 0;
	tmp_stack_a = *stack_a;
	size = ft_listsize(tmp_stack_a);
	max_bits = calculate_max_bits(stack_a);
	while (bit < max_bits)
	{
		nb = 0;
		while (nb++ < size)
		{
			tmp_stack_a = *stack_a;
			if (((tmp_stack_a->index >> bit) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_listsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		bit++;
	}
}
```

#### Steps

1. **Initialization**
   - `bit` is initialized to 0 to begin with the least significant bit.
   - `tmp_stack_a` points to `stack_a`.
   - `size` is calculated using the helper function `ft_listsize()`, which returns the total number of elements in `stack_a`.
   - `max_bits` is calculated using the helper function `calculate_max_bits()`, which determines the number of bits required to represent the largest number in binary.

2. **Outer Loop: `while (bit < max_bits)`**
   - This loop iterates through each bit position, from LSB to MSB.

3. **Inner Loop: `while (nb++ < size)`**
   - This loop processes each element in `stack_a` for the current bit.

   **Steps in the Inner Loop:**
   - `tmp_stack_a` points to the current `stack_a`.

   - The condition checks whether the `bit`-th bit of the current element is 1:
     ```c
     if (((tmp_stack_a->index >> bit) & 1) == 1)
     ```
     - `tmp_stack_a->index >> bit`: Right-shifts the index value by `bit` positions to isolate the `bit`-th bit.
     - `& 1`: Checks if the isolated bit is 1.

   - If the bit is 1:
     - The element remains in `stack_a`, and the `ra(stack_a)` function is called to rotate `stack_a` (shifts all elements up by one position).

   - If the bit is 0:
     - The element is pushed to `stack_b` using the `pb(stack_a, stack_b)` function.

4. **Rebuilding `stack_a`**
   - Once all elements in `stack_a` are processed for the current bit, all elements in `stack_b` are moved back to `stack_a` using the `pa(stack_a, stack_b)` function.
   - This prepares `stack_a` for the next bit pass.

5. **Increment the Bit**
   - The outer loop increments `bit` (`bit++`) to process the next significant bit.

6. **Completion**
   - The function terminates when all bits (`max_bits`) have been processed.
   - At this point, `stack_a` is sorted in ascending order.

### Example Walkthrough

Assume `stack_a` contains `[4, 2, 1, 3]` with indices `[3, 1, 0, 2]`, and `stack_b` is initially empty.

**First Pass (bit = 0)**
- Process each element based on the least significant bit:
  - `3` (binary: `11`) → LSB = 1 → stay in `stack_a`.
  - `1` (binary: `01`) → LSB = 1 → stay in `stack_a`.
  - `0` (binary: `00`) → LSB = 0 → move to `stack_b`.
  - `2` (binary: `10`) → LSB = 0 → move to `stack_b`.

- After the pass:
  - `stack_a`: `[3, 1]`
  - `stack_b`: `[0, 2]`

- Rebuild `stack_a`:
  - `stack_a`: `[3, 1, 0, 2]`
  - `stack_b`: `[]`.

**Second Pass (bit = 1)**
- Process each element based on the second least significant bit:
  - `3` (binary: `11`) → 2nd bit = 1 → stay in `stack_a`.
  - `1` (binary: `01`) → 2nd bit = 0 → move to `stack_b`.
  - `0` (binary: `00`) → 2nd bit = 0 → move to `stack_b`.
  - `2` (binary: `10`) → 2nd bit = 1 → stay in `stack_a`.

- After the pass:
  - `stack_a`: `[3, 2]`
  - `stack_b`: `[1, 0]`

- Rebuild `stack_a`:
  - `stack_a`: `[3, 2, 1, 0]`
  - `stack_b`: `[]`.

**Third Pass (bit = 2)**
- Continue processing until all bits are handled.

**Final Output**
- At the end of all passes, `stack_a` is sorted in ascending order.

### Handling Negative Numbers in Radix Sort

In `radix_sort`, negative numbers do not pose a problem because all elements in `stack_a` are first assigned **indices** based on their relative order, rather than using their actual values.

For example, if `stack_a` contains `[4, -2, -4, 0]`, these numbers are sorted and mapped to indices:

- **-4** (smallest) → index **0**  
- **-2** → index **1**  
- **0** → index **2**  
- **4** (largest) → index **3**  

The algorithm operates on these **indices** (which are always non-negative), rather than the original values. This ensures the sorting logic works seamlessly, regardless of whether the input contains negative numbers.

### Complexity

- **Time Complexity:** `O(n * k)`, where:
  - `n`: Number of elements.
  - `k`: Number of bits in the largest number.

- **Space Complexity:** `O(n)`, for auxiliary stacks.
