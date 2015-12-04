#include "linear/log.h"
#include "linear/server.h"

#include "server_impl.h"

using namespace linear::log;

namespace linear {

Error Server::SetMaxClients(int max_clients) const {
  if (!server_) {
    return Error(LNR_EINVAL);
  }
  server_->SetMaxLimit(max_clients);
  return Error(LNR_OK);
}

Error Server::Start(const std::string& host, int port) const {
  if (!server_) {
    return Error(LNR_EINVAL);
  }
  Error e(LNR_ENOMEM);
  try {
    EventLoop::ServerEvent* ev = new EventLoop::ServerEvent(server_);
    e = server_->Start(host, port, ev);
    if (e != Error(LNR_OK)) {
      delete ev;
    }
  } catch(...) {
    LINEAR_LOG(LOG_ERR, "no memory");
  }
  return e;
}

Error Server::Stop() const {
  if (!server_) {
    return Error(LNR_EALREADY);
  }
  return server_->Stop();
}

} // namespace linear
