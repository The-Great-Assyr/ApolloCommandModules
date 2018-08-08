#include "ApolloCommandModules.hpp"

struct ReferenceOscillator : Module {
    enum ParamIds {
        NUM_PARAMS
    };
    enum InputIds {
        NUM_INPUTS
    };
    enum OutputIds {
        SINE_OUTPUT,
        NUM_OUTPUTS
    };
    enum LightIds {
        NUM_LIGHTS
    };
    float phase = 0.0;

    ReferenceOscillator() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {}
    void step() override;
};

void
ReferenceOscillator::step()
{
    float delta_time = engineGetSampleTime();
    float frequency = 440.0;

    phase += frequency * delta_time;
    if (phase >= 1.0f) {
        phase -= 1.0f;
    }

    float sine = sinf(2.0f * M_PI * phase);
    outputs[SINE_OUTPUT].value = sine;
}

struct ReferenceOscillatorWidget : ModuleWidget {
    ReferenceOscillatorWidget(ReferenceOscillator *module) : ModuleWidget(module) {
        setPanel(SVG::load(assetPlugin(plugin, "res/ReferenceOscillator.svg")));
        addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
        addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
        addOutput(Port::create<PJ301MPort>(Vec(10, 325), Port::OUTPUT, module, ReferenceOscillator::SINE_OUTPUT));
    }
};

Model *modelReferenceOscillator = Model::create<ReferenceOscillator, ReferenceOscillatorWidget>("Apollo Command Modules", "ReferenceOscillator", "440 Hz Reference Oscillator", OSCILLATOR_TAG);
