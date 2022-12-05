package chain_of_responsibility

type iHandler interface {
	Handle(request *Request) bool
	SetNext(handler iHandler) iHandler
	Next() iHandler
}

type Handler struct {
	next iHandler
}

func (h *Handler) SetNext(handler iHandler) iHandler {
	h.next = handler
	return h.next
}

func (h *Handler) Next() iHandler {
	return h.next
}

type UserHandler struct {
	Handler
}
func (h UserHandler) Handle(request *Request) (result bool) {
	if request.Username == "root" && request.Password == "root" {
		println("UserHandler: Valid user", request.Username)
		println("Next handler is", h.next)
		if h.next != nil {
			result = h.next.Handle(request)
		} else {
			result = true
		}
	} else {
		println("UserHandler: Invalid username & password")
		result = false
	}
	return
}

type IpHandler struct {
	Handler
}
func (h *IpHandler) Handle(request *Request) (result bool) {
	if request.IP == "10.10.10.10" {
		println("IpHandler: Valid IP", request.IP)
		if h.next != nil {
			result = h.next.Handle(request)
		} else {
			result = true
		}
	} else {
		println("IpHandler: Invalid ip", request.IP)
		result = false
	}
	return
}

type HandlerManager struct {
	handler iHandler
}

func (hm *HandlerManager) GetHandler(handler string) iHandler {
	hm.handler = &UserHandler{}
	switch handler {
	case "user_ip":
	println("HandlerManager: Creating user and ip handler")
	hm.handler.SetNext(&IpHandler{})
	case "user":
	println("HandlerManager: Creating user handler")
	}
	return hm.handler
}

func NewHandlerManager() *HandlerManager {
	return &HandlerManager{}
}
