// Copyright (c) 2017-2020, Mudita Sp. z.o.o. All rights reserved.
// For licensing, see https://github.com/mudita/MuditaOS/LICENSE.md

#pragma once

#include "WorkerDesktop.hpp"
#include "UpdateMuditaOS.hpp"
#include "module-services/service-desktop/endpoints/update/UpdateEndpoint.hpp"

namespace service::name
{
    const inline std::string service_desktop = "ServiceDesktop";
};

namespace sdesktop
{
    const inline int service_stack         = 8192;
    const inline int cdc_queue_len         = 10;
    const inline int cdc_queue_object_size = 10;
    const inline int file_transfer_timeout = 5000;
}; // namespace sdesktop

class ServiceDesktop : public sys::Service
{
  public:
    ServiceDesktop();
    ~ServiceDesktop() override;
    sys::ReturnCodes InitHandler() override;
    sys::ReturnCodes DeinitHandler() override;
    sys::ReturnCodes SwitchPowerModeHandler(const sys::ServicePowerMode mode) override;
    sys::Message_t DataReceivedHandler(sys::DataMessage *msg, sys::ResponseMessage *resp) override;

    // upload and download from the service perspective (download to phone, upload to computer)
    sys::ReturnCodes startDownload(const fs::path &destinationFile, const uint32_t fileSize);
    sys::ReturnCodes startUpload(const fs::path &sourceFile, const uint32_t fileSize);

    std::unique_ptr<UpdateMuditaOS> updateOS;
    std::unique_ptr<WorkerDesktop> desktopWorker;
};
