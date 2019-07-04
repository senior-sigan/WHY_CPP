#pragma once

class Context;
struct ApplicationConfig;
class ApplicationListener;

void SetupContext(Context& ctx, const ApplicationConfig& config, ApplicationListener* listener);
