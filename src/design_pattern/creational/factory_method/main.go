package main

import (
	v1 "factory_method/v1"
	v2 "factory_method/v2"
	v3 "factory_method/v3"
	"fmt"
)

func main() {
	fmt.Println("Factory Method Demo V1 ...")
	v1.Work()

	fmt.Println("Factory Method Demo V2 ...")
	v2.Work()

	fmt.Println("Factory Method Demo V3 ...")
	v3.Work()
}
