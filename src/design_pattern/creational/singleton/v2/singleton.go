package v2

import (
	"fmt"
)

type singleton struct {
	name string
}

var instance *singleton

func GetInstance(name string) *singleton {
	if instance == nil {
		instance = &singleton{name: name}
		fmt.Println(">>> create instance:", name)
	} else {
		fmt.Println(">>> unable to created:", name)
	}
	return instance
}

func init() {
	fmt.Println(">>> v2 init")
	instance = &singleton{name: "default"}
}
