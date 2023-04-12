li[n]: limit
solve(n)
    q = -1e9
    for i from 1 to n / 2
        if(li[i])
            li[i]--
            q = max(q, p[i] + solve(n - i))
            li[i]++
    if li[n]
        li[n]--
        q = max(q, p[i])
        li[n]++
    return q