// Copyright (c) 2017-2021, Mudita Sp. z.o.o. All rights reserved.
// For licensing, see https://github.com/mudita/MuditaOS/LICENSE.md

#pragma once

#include <hal/battery_charger/AbstractBatteryCharger.hpp>

namespace hal::battery
{
    class BatteryCharger : public AbstractBatteryCharger
    {
      public:
        explicit BatteryCharger(AbstractBatteryCharger::BatteryChargerEvents &eventsHandler);
        void init(xQueueHandle irqQueueHandle, xQueueHandle dcdQueueHandle) final;
        void deinit() final;
        void processStateChangeNotification(std::uint8_t notification) final;
        void setChargingCurrentLimit(std::uint8_t usbType) final;
        int getBatteryVoltage() final;

      private:
        AbstractBatteryCharger::BatteryChargerEvents &eventsHandler;
    };
} // namespace hal::battery
