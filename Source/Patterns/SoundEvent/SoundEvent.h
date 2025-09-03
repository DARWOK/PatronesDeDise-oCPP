/**
 * @file SoundEvent.h
 * @brief Tipos de evento de audio y estructura comparable para Event Queue.
 */
#pragma once

enum class SoundID { HIT, JUMP, DEATH };

struct SoundEvent {
    SoundID id;
    bool operator==(const SoundEvent& other) const {
        return id == other.id;
    }
};