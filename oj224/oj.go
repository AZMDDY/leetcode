package oj224

func calculate(s string) int {
	sign := []int{}
	sign = append(sign, 1)
	ans := 0
	num := 0
	op := 1
	for _, v := range s {
		if v >= '0' && v <= '9' {
			num = num*10 + int(v-'0')
			continue
		}
		ans += num * op
		num = 0
		if v == '+' {
			op = sign[len(sign)-1]
		} else if v == '-' {
			op = -sign[len(sign)-1]
		} else if v == '(' {
			sign = append(sign, op)
		} else if v == ')' {
			sign = sign[:len(sign)-1]
		}
	}
	return ans + op*num
}
