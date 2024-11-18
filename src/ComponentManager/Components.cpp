/*
** EPITECH PROJECT, 2024
** GE [WSL: Ubuntu]
** File description:
** Components.cpp
*/

#include "Components.hpp"
#include "ECS/Entity.h"
#include "ECS/ECS.hpp"

#include <typeinfo>
#include <glm/glm.hpp>

namespace ECS::Components
{
    void PositionsComponents::AddToEntity(Entity &entity, va_list args, ...)
    {
            va_start(args, args);
            m_positions.emplace_back(
                    va_arg(args, double),
                    va_arg(args, double)
            );
            va_end(args);
            IdToIndex_p[entity.id] = m_positions.size() - 1;
            entity.componentsName.insert(typeid(PositionsComponents).name());
    }

    void PositionsComponents::RemoveFromEntity(Entity &entity)
    {
        std::size_t index = IdToIndex_p[entity.id];

        std::swap(m_positions[index], m_positions.back());
        m_positions.pop_back();
        entity.componentsName.erase(typeid(PositionsComponents).name());
        IdToIndex_p.erase(index);
    }

    void SpriteComponents::AddToEntity(Entity &entity, va_list args, ...)
    {
        va_start(args, args);
        std::string path(va_arg(args, char *));

        if (std::find_if(_alreadyLoaded.begin(), _alreadyLoaded.end(), [&path](const std::pair<std::string, std::size_t> &pair) {
            return pair.first == path;
        }) != _alreadyLoaded.end()) {
            m_texture.emplace_back(sf::Texture(), m_vertexArray.size());
            m_texture.back().first.loadFromFile(path);
            m_vertexArray.emplace_back(sf::Quads, 4);
            _alreadyLoaded.emplace_back(path, m_texture.size() - 1);
            IdToIndex_p[entity.id] = m_texture.size() - 1;
        } else {
            IdToIndex_p[entity.id] = _alreadyLoaded[path].second;
        }

        entity.componentsName.insert(typeid(SpriteComponents).name());
        (*ECS::ECS::GetInstance().getSystemsManager())[SystemsManager::SystemType::SPRITE]->AddEntity(entity);
    }

    void SpriteComponents::RemoveFromEntity(Entity &entity)
    {
        std::size_t index = IdToIndex_p[entity.id];

        entity.componentsName.erase(typeid(PositionsComponents).name());
        IdToIndex_p.erase(index);
    }

    void TransformComponents::AddToEntity(Entity &entity, va_list args, ...)
    {
        va_start(args, args);
        m_positions.emplace_back(
            va_arg(args, double),
            va_arg(args, double)
        );
        m_scales.emplace_back(va_arg(args, double));
        m_transforms.emplace_back(
            va_arg(args, double),
            va_arg(args, double),
            va_arg(args, double),
            va_arg(args, double)
        );
        va_end(args);
        IdToIndex_p[entity.id] = m_positions.size() - 1;
        entity.componentsName.insert(typeid(TransformComponents).name());

    }

    void TransformComponents::RemoveFromEntity(Entity &entity)
    {
        std::size_t index = IdToIndex_p[entity.id];

        std::swap(m_positions[index], m_positions.back());
        std::swap(m_scales[index], m_scales.back());
        std::swap(m_transforms[index], m_transforms.back());
        m_positions.pop_back();
        m_scales.pop_back();
        m_transforms.pop_back();
        entity.componentsName.erase(typeid(TransformComponents).name());
        IdToIndex_p.erase(index);
    }
}
