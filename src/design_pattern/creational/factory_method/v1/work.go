package v1

import "fmt"

type Porsche struct {
	owner string
	speed float32
}

func (p *Porsche) drive() string {
	return fmt.Sprintf("%s is driving a Porsche at %f km/h.", p.owner, p.speed)
}

// def Work():
//     porsche = Porsche('Hans', 330.0)
//     print(porsche.drive())
//     # ferrari = Ferrari('Henry', 341.0)
//     # ...

func Work() {
	v := &Porsche{owner: "Hans", speed: 330.0}
	fmt.Println(v.drive())
	// ferrari := &Ferrari{owner: "Henry", speed: 341.0}
	// ...
}
