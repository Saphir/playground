package chain_of_responsibility

func Work() {
	println("Chain of responsibility pattern in Go")
	request := NewRequest()
	request.Username = "root"
	request.Password = "root"
	request.IP = "10.20.30.40"
	handlerManager := NewHandlerManager()

	handler1 := handlerManager.GetHandler("user")
	println("Handler 1 check user only and the result is", handler1.Handle(request))

	handler2 := handlerManager.GetHandler("user_ip")
	println("Handler 2 check user and ip and the result is", handler2.Handle(request))
}
