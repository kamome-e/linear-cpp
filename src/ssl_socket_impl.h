#ifndef LINEAR_SSL_SOCKET_IMPL_H_
#define LINEAR_SSL_SOCKET_IMPL_H_

#include "linear/ssl_context.h"

#include "socket_impl.h"

namespace linear {

class SSLSocketImpl : public linear::SocketImpl {
 public:
  // Client Socket
  SSLSocketImpl(const std::string& host, int port, const linear::SSLContext& context,
                const linear::HandlerDelegate& delegate);
  // Server Socket
  SSLSocketImpl(tv_stream_t* stream, const SSLContext& context,
                const linear::HandlerDelegate& delegate);
  virtual ~SSLSocketImpl();
  linear::Error Connect();
  linear::Error GetVerifyResult();
  bool PresentPeerCertificate();
  linear::X509Certificate GetPeerCertificate();

 private:
  linear::SSLContext context_;
};

}  // namespace linear

#endif  // LINEAR_SSL_SOCKET_IMPL_H_
