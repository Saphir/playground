package visitor

import "fmt"

type LaoWang struct {
	money float64
}
func (l *LaoWang) visit(r* Rate) {
	if r.r.Name() == "Rmb" {
		result := l.money / r.r.GetRate()
		fmt.Printf("Laowang exchanges %0.2f Rmb to %0.2f doller\n", l.money, result)
	}
}