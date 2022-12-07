package visitor

import "fmt"

type Joy struct {
	money float64
}
func (j *Joy) visit(r* Rate) {
	result := j.money * r.r.GetRate()
	fmt.Printf("Joy exchanges %0.2f doller to %0.2f %s\n", j.money, result, r.r.Name())
}