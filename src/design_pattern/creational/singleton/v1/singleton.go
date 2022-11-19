package v1

import (
	"fmt"
	"sync"
)

type singleton struct {
	name string
}

var lock = &sync.Mutex{}
var instance *singleton

func GetInstance(name string) *singleton {
	if instance == nil {
		lock.Lock()
		defer lock.Unlock()
		if instance == nil {
			instance = &singleton{name: name}
			fmt.Println(">>> create instance:", name)
		} else {
			fmt.Println(">>> unable to created:", name)
		}
	} else {
		fmt.Println(">>> unable to created:", name)
	}
	return instance
}
