package pj1047

func removeDuplicates(S string) string {
	stk := []byte{}
	for i := range S {
		if len(stk) > 0 && stk[len(stk)-1] == S[i] {
			stk = stk[:len(stk)-1]
		} else {
			stk = append(stk, S[i])
		}
	}
	return string(stk)
}
