#include "ApolloCommandModules.hpp"

struct SignalSplitter : Module {
    enum ParamIds {
        NUM_PARAMS
    };
    enum InputIds {
        INPUT_A,
        INPUT_B,
        NUM_INPUTS
    };
    enum OutputIds {
        OUTPUT_A1,
        OUTPUT_A2,
        OUTPUT_A3,
        OUTPUT_B1,
        OUTPUT_B2,
        OUTPUT_B3,
        NUM_OUTPUTS
    };
    enum LightIds {
        NUM_LIGHTS
    };
    void step() override;

    SignalSplitter() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {}
};

void
SignalSplitter::step()
{
    outputs[OUTPUT_A1].value = inputs[INPUT_A].value;
    outputs[OUTPUT_A2].value = inputs[INPUT_A].value;
    outputs[OUTPUT_A3].value = inputs[INPUT_A].value;
    outputs[OUTPUT_B1].value = inputs[INPUT_B].value;
    outputs[OUTPUT_B2].value = inputs[INPUT_B].value;
    outputs[OUTPUT_B3].value = inputs[INPUT_B].value;
}

struct
SignalSplitterWidget : ModuleWidget {
    SignalSplitterWidget(SignalSplitter *module) : ModuleWidget(module) {
        setPanel(SVG::load(assetPlugin(plugin, "res/SignalSplitter.svg")));
        addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
        addChild(Widget::create<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
        addInput(Port::create<CL1362Port>(Vec(6, 45), Port::INPUT, module, SignalSplitter::INPUT_A));
        addOutput(Port::create<CL1362Port>(Vec(6, 80), Port::OUTPUT, module, SignalSplitter::OUTPUT_A1));
        addOutput(Port::create<CL1362Port>(Vec(6, 115), Port::OUTPUT, module, SignalSplitter::OUTPUT_A2));
        addOutput(Port::create<CL1362Port>(Vec(6, 150), Port::OUTPUT, module, SignalSplitter::OUTPUT_A3));
        addInput(Port::create<CL1362Port>(Vec(6, 220), Port::INPUT, module, SignalSplitter::INPUT_B));
        addOutput(Port::create<CL1362Port>(Vec(6, 255), Port::OUTPUT, module, SignalSplitter::OUTPUT_B1));
        addOutput(Port::create<CL1362Port>(Vec(6, 290), Port::OUTPUT, module, SignalSplitter::OUTPUT_B2));
        addOutput(Port::create<CL1362Port>(Vec(6, 325), Port::OUTPUT, module, SignalSplitter::OUTPUT_B3));
    }
};

Model *SignalSplitterModel = Model::create<SignalSplitter, SignalSplitterWidget>("Apollo Command Modules", "SignalSplitter", "Signal Splitter", UTILITY_TAG);
