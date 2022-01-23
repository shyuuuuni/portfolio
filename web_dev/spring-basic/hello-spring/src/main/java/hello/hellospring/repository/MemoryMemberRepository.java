package hello.hellospring.repository;

import hello.hellospring.domain.Member;
import org.springframework.stereotype.Repository;

import java.util.*;

// 클래스로 생성 -> implements ... 치고 옵션+엔터 -> Override method 불러옴
//@Repository
public class MemoryMemberRepository implements MemberRepository {
    // 메모리 저장소 생성
    private static Map<Long, Member> store = new HashMap<>();
    private static long sequence = 0L;

    @Override
    public Member save(Member member) {
        member.setId(++sequence);
        store.put(member.getId(), member);
        return member;
    }

    @Override
    public Optional<Member> findById(Long id) {
        // 결과가 없으면 Null 가능
        // 요즘에는 Null 반환 가능때문에 Optional로 감쌈
        return Optional.ofNullable(store.get(id));
    }

    @Override
    public Optional<Member> findByName(String name) {
        // loop를 돌면서 걔를 찾으면 리턴 아니면 Optional로 감쌈.
        return store.values().stream()
                .filter(member -> member.getName().equals(name))
                .findAny();
    }

    @Override
    public List<Member> findAll() {
        // 실무에서는 리스트를 많이 쓴다.
        return new ArrayList<>(store.values());
    }

    public void clearStore() {
        store.clear();
    }
}
