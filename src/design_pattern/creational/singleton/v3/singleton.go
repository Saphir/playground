package v3

import (
	"fmt"
	"sync"
)

type singleton struct {
	name string
}

var once sync.Once
var instance *singleton

func GetInstance(name string) *singleton {
	if instance == nil {
		once.Do(func() {
			instance = &singleton{name: name}
			fmt.Println(">>> create instance:", name)
		})
	} else {
		fmt.Println(">>> unable to created:", name)
	}
	return instance
}
