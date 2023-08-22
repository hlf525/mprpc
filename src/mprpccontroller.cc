#include "mprpccontroller.h"

    MprpcController::MprpcController()
    {
        m_failed = false;
        m_errText = "";
    }

    void MprpcController::Reset()
    {
        m_failed = false;//最初认为它是正确的
        m_errText = "";
    }

    bool MprpcController::Failed() const
    {
        return m_failed;
    }

    std::string MprpcController::ErrorText() const
    {
        return m_errText;
    }

    void MprpcController::SetFailed(const std::string& reason)
    {
        m_failed = true;//发生问题
        m_errText = reason;//错误的具体信息
    }

    //目前未实现的具体功能
    void MprpcController::StartCancel(){}
    bool MprpcController::IsCanceled() const{ return false; }
    void MprpcController::NotifyOnCancel(google::protobuf::Closure* callback){}